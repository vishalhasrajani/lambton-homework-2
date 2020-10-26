f_input = 1000;  #Input Frequency
v_input = 2;     #Input Voltage
s_input = 2*f_input;
t_input = 15*(0:1/100000000:2.*(1/s_input));



f_carrier = 10000;  #Carrier Frequency
v_carrier = 5;      #Carrier Voltage
s_carrier = 2*f_carrier;
t_carrier = 15*(0:1/100000000:2.*(1/s_carrier));

modulation_degree=0.5;  #Modulation Degree

sig_input =   v_input*cos(2*pi*f_input*t_input); # Input Signal
sig_carrier = v_carrier*cos(2*pi*f_carrier*t_input); # Carrier Signal
sig_AM  = (1+modulation_degree*sig_input).*sig_carrier; # Modulated 

subplot(3,1,1)
plot(t_input,sig_input);
title("Input Signal");

subplot(3,1,2)
plot(t_input,sig_carrier);
title("Carrier Signal");

subplot(3,1,3)
plot(t_input,sig_AM);
title("AM Signal");