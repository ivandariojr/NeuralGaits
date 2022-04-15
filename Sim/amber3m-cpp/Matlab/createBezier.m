%% createBezier
% A script to create CPP Bezier functions.
%
% Written by: Noel Csomay-Shanklin
% Date of last edit: 7/10/20

%% DEBUG
getBezier(5)

%%
create_beziers(2:6);

%% Write CPP
function create_beziers(n)
[cpp_fh,msg1] = fopen('Bezier.cpp','w');
[hpp_fh,msg2] = fopen('Bezier.hpp','w');
if cpp_fh < 0; disp(msg1); end
if hpp_fh < 0; disp(msg2); end

fprintf(hpp_fh,'#ifndef BEZIER_H\n#define BEZIER_H\n');
fprintf(hpp_fh,'#include<Eigen/Dense>\n\n');
fprintf(hpp_fh,'using void_f1_ptr = float (*)(float, Eigen::VectorXd);');
fprintf(hpp_fh,'void_f1_ptr genBezier(int size, void_f1_ptr fp);\n');
fprintf(hpp_fh,'void_f1_ptr genBezierDot(int size,void_f1_ptr fp);\n\n');
for i = n
fprintf(hpp_fh,['float B' num2str(i) '(float t, Eigen::VectorXd alpha);\n']);
fprintf(hpp_fh,['float B' num2str(i) '_dot(float t,Eigen::VectorXd alpha);\n']);
end
fprintf(hpp_fh,'#endif');
fclose(hpp_fh);

fprintf(cpp_fh,'#include "Bezier.hpp"\n\n');
fprintf(cpp_fh,'void_f1_ptr genBezier(int size, void_f1_ptr fp) {\n');
fprintf(cpp_fh,'  switch(size){\n');
for i = n
fprintf(cpp_fh,['  case ' num2str(i) ':\n']);
fprintf(cpp_fh,['  	fp = &B' num2str(i) '; break;\n']);
end
fprintf(cpp_fh,'  }\n');
fprintf(cpp_fh,'  return fp;\n');
fprintf(cpp_fh,'}\n\n');
fprintf(cpp_fh,'void_f1_ptr genBezierDot(int size, void_f1_ptr fp) {\n');
fprintf(cpp_fh,'  switch(size){\n');
for i = n
fprintf(cpp_fh,['  case ' num2str(i) ':\n']);
fprintf(cpp_fh,['  	fp = &B' num2str(i) '_dot; break;\n']);
end
fprintf(cpp_fh,'  }\n');
fprintf(cpp_fh,'  return fp;\n');
fprintf(cpp_fh,'}\n\n');
for i = n
fprintf(cpp_fh,getBezier(i));
fprintf(cpp_fh,getBezierDerivative(i));
end
fclose(cpp_fh);
end

%% Generate Bezier
function B = getBezier(n)
B = ['pow(1-t,' num2str(n) ')*alpha[0]'];
for i = 1:n-1
B = [B '+' [num2str(nchoosek(n,i)) '*pow(1-t,' num2str(n-i) ')*pow(t,' num2str(i) ')*alpha[' num2str(i) ']']];
end
B = [B '+' 'pow(t,' num2str(n) ')*alpha[' num2str(n) ']'];
B = ['float B' num2str(n) '(float t,Eigen::VectorXd alpha){return ' B ';}\n'];
end

%% Generate Bezier Derivative
function B = getBezierDerivative(n)

B = [num2str(n) '*pow(1-t,' num2str(n-1) ')*(alpha[1]-alpha[0])'];
for i = 1:n-2
B = [B '+' [num2str(nchoosek(n-1,i)) '*pow(1-t,' num2str(n-1-i) ')*pow(t,' num2str(i) ')*(alpha[' num2str(i+1) ']-alpha[' num2str(i) '])']];
end
B = [B '+' 'pow(t,' num2str(n-1) ')*(alpha[' num2str(n) ']-alpha[' num2str(n-1) '])'];
B = ['float B' num2str(n) '_dot(float t,Eigen::VectorXd alpha){return ' B ';}\n'];
end

