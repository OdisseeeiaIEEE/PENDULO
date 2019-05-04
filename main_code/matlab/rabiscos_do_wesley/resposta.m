A = [0 1 0 0; 20.601 0 0 0;0 0 0 1;0 0 0 0];
B = [0;-1;0;0.5];
C = [0 0 1 0];
D = [0];
K = [-157.6336 -35.3733 -56.0652 -36.7466];
KI = -50.9684;
AA = [A - B*K B*KI;-C 0];
BB = [0;0;0;0;1];11     
CC = [C 0];
DD = [0];

t =0:0.02:6;
[y,x,t] = step(AA,BB,CC,DD,1,t);

x1 = [1 0 0 0 0]*x';
x2 = [0 1 0 0 0]*x';
x3 = [0 0 1 0 0]*x';
x4 = [0 0 0 1 0]*x';
x5 = [0 0 0 0 1]*x';

subplot(3,2,1); plot(t,x1); grid
title('x1 versus t')
xlabel('t (s)'); ylabel('x1')

subplot(3,2,2); plot(t,x2); grid
title('x2 versus t')
xlabel('t (s)'); ylabel('x2')

subplot(3,2,3); plot(t,x3); grid
title('x3 versus t')
xlabel('t (s)'); ylabel('x3')

subplot(3,2,4); plot(t,x4); grid
title('x4 versus t')
xlabel('t (s)'); ylabel('x4')

%valor xi%
%u = -Kx + Ki*xi%
subplot(3,2,5); plot(t,x5); grid
title('x5 versus t')
xlabel('t (s)'); ylabel('x5')



