% Example of mixed integer problem
% This example corresponds to MEIGO toolbox example: ex3.m
% http://gingproc.iim.csic.es/meigo.html

function [F g]=matlabMINLP(X)

F = X(2)^2 + X(3)^2 + 2.0*X(1)^2 + X(4)^2 - 5.0*X(2) - 5.0*X(3) - 21.0*X(1) + 7.0*X(4);
g(1) = X(2)^2 + X(3)^2 + X(1)^2 + X(4)^2 + X(2) - X(3) + X(1) - X(4);
g(2) = X(2)^2 + 2.0*X(3)^2 + X(1)^2 + 2.0*X(4)^2 - X(2) - X(4);
g(3) = 2.0*X(2)^2 + X(3)^2 + X(1)^2 + 2.0*X(2) - X(3) - X(4);
return
