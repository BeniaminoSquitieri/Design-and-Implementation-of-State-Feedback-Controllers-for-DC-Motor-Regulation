function xdot = stato(x,r)
    tau=1.015;
    k = 6.7917;

    % Stati

    x2 = x(1)
    ux = x(2)
    r=x(3)
    % Derivate degli stati
    x2_dot = -1/tau * x2 + k/tau * ux
    z_dot=x2-r
    % Assegna i valori di x1_dot e x2_dot a xdot
    xdot = [x2_dot; z_dot]
end


