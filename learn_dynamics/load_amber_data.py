import pandas as pd
from pathlib import Path
from torch.utils.data import Dataset
from torch.utils.data.dataset import T_co
import torch as th
import numpy as np

data_root = Path(__file__).parent / 'data'

HEADER = ["t","tau","switchBack","tau_d","tau_a","stance","fullState_1","fullState_2","fullState_3","fullState_4","fullState_5","fullState_6","fullState_7","fullState_8","fullState_9","fullState_10","desState1","desState2","desState3","desState4","desState5","desState6","desState7","desState8","torque1","torque2","torque3","torque4","u_des1","u_des2","u_des3","u_des4","idk1","idk2","idk3","idk4","idk5","idk6"]

class AmberRealDataSet(Dataset):

    def __init__(self, dataset_names, delta_t, n_steps) -> None:
        super().__init__()
        file_paths = list(data_root.iterdir())
        # file_names = [f.name.split('.')[0] for f in file_paths]
        data_frames = []
        if "ALL" in dataset_names:
            for f_p in file_paths:
                data_frames += [pd.read_csv(f_p, sep=',',
                                            skiprows=1,
                                            names=HEADER,
                                            index_col=False)]
        else:
            for d_n in dataset_names:
                data_frames += [
                    pd.read_csv(data_root / f'{d_n}.csv', sep=',',
                                skiprows=1,
                                names=HEADER, index_col=False)
                ]
        #correct for startup timer
        ds_tensors = []
        for df in data_frames:
            ds_tensor = th.tensor(df.to_numpy(dtype=np.float32))
            # ds_tensor_np = ds_tensor.numpy()
            # import matplotlib.pyplot as plt
            # ts = ds_tensor_np[:, 0]
            # xt = ds_tensor_np[:, 6:16]
            # ut = ds_tensor_np[:, 24:]
            # plt.plot(ts)
            # plt.show()

            # plt.plot(xt[:, 0])
            # plt.show()
            # for idx in range(5):
            #     plt.plot(ts, xt[:, idx])
            #     plt.show()
            # for idx in range(5):
            #     plt.plot(ts, xt[:, 5+idx])
            #     plt.show()
            # for idx in range(4):
            #     plt.plot(ts, ut[:, idx])
            #     plt.show()
            ds_tensors += [ds_tensor[ds_tensor[:, 0] > 15000.0, :]]
        ds_time_corrected_tensors = []
        sequence_dataset = []
        for ds_tensor in ds_tensors:
            ds_time_corrected_tensor = [ds_tensor[0]]
            delta_ts = ds_tensor[1:, 0] - ds_tensor[:-1, 0]
            t_curr_window = 0.0
            for idx in range(1, ds_tensor.shape[0]):
                if delta_ts[idx-1].item() > 2.5 or \
                    (len(ds_time_corrected_tensor) > 0 and (
                      ds_time_corrected_tensor[-1][5] != ds_tensor[idx, 5]).item()):
                    #this is likely to be a bad measurement.
                    t_curr_window = 0.0
                    if len(ds_time_corrected_tensor) < n_steps:
                        ds_time_corrected_tensor = []
                        continue
                    ds_time_corrected_tensor = th.stack(
                        ds_time_corrected_tensor, dim=0)
                    ds_time_corrected_tensors += [ds_time_corrected_tensor]
                    ds_time_corrected_tensor = []
                    continue
                t_curr_window_next = t_curr_window + delta_ts[idx-1].item()
                if t_curr_window_next > delta_t:
                    # print("Add Element")
                    window_overshoot = abs(t_curr_window_next - delta_t)
                    window_undershoot = abs(delta_t -t_curr_window)
                    if window_overshoot <=window_undershoot:
                        #better to end window on this one
                        t_curr_window = 0.0
                        ds_time_corrected_tensor += [ds_tensor[idx]]
                    else:
                        #better to have ended window on previous one
                        t_curr_window = delta_ts[idx-1].item()
                        ds_time_corrected_tensor += [ds_tensor[idx-1]]
                else:
                    # print("add next")
                    t_curr_window = t_curr_window_next
            if len(ds_time_corrected_tensor) > 0:
                ds_time_corrected_tensor = th.stack(ds_time_corrected_tensor, dim=0)
                if ds_time_corrected_tensor.shape[0] < n_steps:
                    continue
                ds_time_corrected_tensors += [ds_time_corrected_tensor]

        for ds_time_corrected_tensor in ds_time_corrected_tensors:
            sequence_dataset += [th.stack(
                [ds_time_corrected_tensor[idx: idx+n_steps]
                for idx in range(ds_time_corrected_tensor.shape[0]-n_steps+1)], dim=0)
            ]

        self.sequence_dataset = th.cat(sequence_dataset, dim=0)
        #time_error debug plotting stuff
        # delta_ts = []
        # for ds_tmp  in ds_corrected_horizons:
        #     delta_ts += [ds_tmp[1:, 0] - ds_tmp[:-1, 0]]
        # delta_ts = th.cat(delta_ts)
        # import matplotlib.pyplot as plt
        # plt.plot(range(delta_ts.shape[0]), delta_ts.detach().numpy())
        # plt.show()

    def __getitem__(self, index) -> T_co:
        return self.sequence_dataset[index]

    def __len__(self):
        return self.sequence_dataset.shape[0]

if __name__ == '__main__':
    dataset = AmberRealDataSet("ALL", delta_t=10., n_steps=10)