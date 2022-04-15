rootdir = './codegen/lib';
dirinfo = dir(fullfile(rootdir));  %get list of files and folders in any subfolder
dirinfo(~[dirinfo.isdir]) = [];  %remove non-directories
subdirinfo = cell(length(dirinfo));
for K = 1 : length(dirinfo)
    thisdir = dirinfo(K).name;
    subdirinfo{K} = dir(fullfile([rootdir '/' thisdir], '*.h'));
    for i = 1:length(subdirinfo{K})
        fh = fopen([rootdir '/' thisdir '/' subdirinfo{K}(i).name]);
        fh_out = fopen([rootdir '/' thisdir '/' subdirinfo{K}(i).name '_tmp'],'w');
        l = fgetl(fh);
        while isempty(l) | l~=-1
            if ~strcmp(l,'#include "rtwtypes.h"')
                fprintf(fh_out, l);
                fprintf(fh_out, '\n');
            end
            l = fgetl(fh);
        end
        movefile([rootdir '/' thisdir '/' subdirinfo{K}(i).name '_tmp'],[rootdir '/' thisdir '/' subdirinfo{K}(i).name]);
    end
end