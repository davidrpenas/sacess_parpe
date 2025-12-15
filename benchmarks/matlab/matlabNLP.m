% Example of mixed integer problem
% This example corresponds to MEIGO toolbox example: ex3.m
% http://gingproc.iim.csic.es/meigo.html

function [F g]=matlabNLP(X)
  global k1 k2 k3 k4
 
  F=-X(4);

  save k1 k1;

  %Equality constraints
  g(1)=X(4)-X(3)+X(2)-X(1)+k4*X(4).*X(6);
  g(2)=X(1)-1+k1*X(1).*X(5);
  g(3)=X(2)-X(1)+k2*X(2).*X(6);
  g(4)=X(3)+X(1)-1+k3*X(3).*X(5);
  %Inequality constraint
  g(5)=X(5).^0.5+X(6).^0.5;

return
