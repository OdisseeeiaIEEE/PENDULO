%% ========================================================================
% Inicialização
%==========================================================================

close all;
clear all;
clc;

num_fig = 0;



%% ========================================================================
% Algoritmo de integração numérica
%==========================================================================

t = linspace(0, 6, 10001);

w = 5*rand;
f = exp(-t).*cos(w*t);
int_f = -(exp(-t).*(cos(w*t) - w*sin(w*t)))/(w^2 + 1);

h = t(2) - t(1);
int_num_f = zeros(size(t)); % Pré-alocação de memória
for i = 1:numel(t) % Algoritmo de integração numérica trapezoidal,
    % Tustin, RK2 explícito
    if i == 1
        int_num_f(i) = (h/2)*f(i) - 1/(w^2 + 1);
    else
        int_num_f(i) = int_num_f(i - 1) + (h/2)*(f(i) + f(i - 1));
    end
end

num_fig = num_fig + 1;
figure(num_fig);
plot(t, f, 'r-', 'LineWidth', 2);
hold on all;
plot(t, int_f, 'b--', 'LineWidth', 2);
plot(t, int_num_f, 'g:', 'LineWidth', 2);
legend('f(t)', '\int f(t) dt', 'trapezoidal', 'Location', 'Best');



%% ========================================================================
% Simulação de sistema dinâmico (pêndulo invertido)
%==========================================================================

A = [0 1 0 0; 20.601 0 0 0; 0 0 0 1; -0.4905 0 0 0];
B = [0; -1; 0; 0.5];
C = eye(4);
D = zeros(size(C*B));

K = [157.6336 35.3733 56.0652 36.7466];
kI = 50.9684;

NP = 1e-7;

t = linspace(0, 6, 10001);

sim('modelo_pendulo', t(end), simset('RelTol', 1e-12, 'AbsTol', 1e-12, ...
    'Solver', 'ode4', 'FixedStep', t(2) - t(1)));


%--------------------------------------------------------------------------


% h = t(2) - t(1);
% int_num_f = zeros(size(t)); % Pré-alocação de memória
% for i = 1:numel(t)
%     
%     %%%%%%%%%%
%     % Planta %
%     %%%%%%%%%%
%     
%     if i == 1
%         x(i) = (h/2)*f(i) - 1/(w^2 + 1);
%     else
%         int_num_f(i) = int_num_f(i - 1) + (h/2)*(f(i) + f(i - 1));
%     end
%     
%     
% end


%--------------------------------------------------------------------------


num_fig = num_fig + 1;
figure(num_fig);
plot(t, x1, 'r-', 'LineWidth', 2);
hold on all;
plot(t, zeros(size(t)), 'b--', 'LineWidth', 2);
grid on;
box on;
xlabel('Tempo [s]');
ylabel('x_{1}(t) = \theta(t) [m]');
axis([0 t(end) 1.02*min(x1) 1.02*max(x1)]);



num_fig = num_fig + 1;
figure(num_fig);
plot(t, x3, 'r-', 'LineWidth', 2);
hold on all;
plot(t, r, 'b--', 'LineWidth', 2);
grid on;
box on;
xlabel('Tempo [s]');
ylabel('x_{3}(t) = x(t) [m]');
axis([0 t(end) 1.02*min(x3) 1.02*max(x3)]);