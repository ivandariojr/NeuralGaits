
import torch as th
from pathlib import Path
import argparse


ROOT = Path(__file__).parent.parent
save_path = ROOT / 'run_data' / 'model.thc'


def main(ckpt_path:str, output_path:str):
    ckpt = th.load(ckpt_path)
    model = ckpt['yd']
    th.jit.save(th.jit.script(model), output_path)

if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('--ckpt_path', required=True)
    parser.add_argument('--thc_path', default=str(save_path))
    args = parser.parse_args()
    main(args.ckpt_path, args.thc_path)