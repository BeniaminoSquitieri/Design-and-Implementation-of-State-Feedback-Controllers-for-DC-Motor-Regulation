function xdot = Dynamic_velocity(x,r)
    tau=1.015;
    k = 6.7917;

    % Stati
    x1 = x(1)
    x2 = x(2)
    ux = x(3)
    r=x(4)
    % Derivate degli stati
    x1_dot = x2
    x2_dot = -1/tau * x2 + k/tau * ux
    z_dot=x2-r
    % Assegna i valori di x1_dot e x2_dot a xdot
    xdot = [x1_dot; x2_dot; z_dot]
end


