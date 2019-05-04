A = [0 1 0 0; 20.601 0 0 0; 0 0 0 1; -0.4905 0 0 0];
B = [0; -1; 0; 0.5];
C = [0 0 1 0];

Ahat = [A zeros(4,1); -C 0];
Bhat = [B; 0];

J = [-1+j*sqrt(3) -1-j*sqrt(3) -5 -5 -5];

Khat = acker(Ahat, Bhat, J)

% K1 K2 K3 K4 KI %