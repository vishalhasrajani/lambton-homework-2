f_input = 1000;  #Input Frequency
v_input = 2;     #Input Voltage
s_input = 2*f_input; #Sample input
t_input = 15*(0:1/100000000:2.*(1/s_input));



f_carrier = 10000;  #Carrier Frequency
v_carrier = 5;      #Carrier Voltage
s_carrier = 2*f_carrier; #Sample Carrier
t_carrier = 15*(0:1/100000000:2.*(1/s_carrier));

modulation_degree=0.5;  #Modulation Degree

sig_input =   v_input*cos(2*pi*f_input*t_input); # Input Signal
sig_carrier = v_carrier*cos(2*pi*f_carrier*(t_input+1/1000000)); # Carrier Signal with jitter
sig_AM  = (1+modulation_degree*sig_input).*sig_carrier; # Modulated Signal
sig_error = 6.*rand(size(sig_input));
sig_AM_error = sig_AM +sig_error; #Added noise


for n=min(t_input):1/100000:max(t_input) #Plot the graph in frames...
  
subplot(3,1,1)
plot(t_input,sig_input);
title("Input Signal");
axis([(n) (n+1/1000) min(sig_input) max(sig_input)]) #Axis is enabled to move the graph

subplot(3,1,2)
plot(t_input,sig_carrier);
title("Carrier Signal");
axis([(n) (n+1/1000) min(sig_carrier) max(sig_carrier)])#Axis is enabled to move the graph

subplot(3,1,3)
plot(t_input,sig_AM_error);
title("AM Signal Error");
axis([(n) (n+1/1000) min(sig_AM_error) max(sig_AM_error)])#Axis is enabled to move the graph

drawnow #draw the new plot on the graph
end