Smart Traffic System Project:-
Tech Used - (object detection using yolo, PhP , Arduino (c++) , ESP 32 , ESP32 Cam )
Idea:-
The Aim is to create an Ambulance Priority System where Ambulances are given the right of way at any intersection and the Traffic Cycles can be modified to provide the same, resulting in the timely arrival of ambulances 
and emergency services potentially saving lives. 

Setup / Training:-
We set up An ESP 32 Cam to capture the images of 2 Vehicles (or toys) One which is a general car and the other which is an Ambulance. Now Boot up the Arduino IDE and run the inbult Image Collector to collect 
images of the  vehicles and store it into 2 seperate folders to use for training. Now Find any Yolo/ Object Recognition No Code Models and Submit these images into 2 categories (General and Ambulance). Now 
select the region where the vechile is present in every photo and label it. Once labeling is done, feed this data and train the model. Once it is done we can expot the code as an arduino Libray and  easily 
use it for the upcoming processes. Now set up annother ESP 32 which will act as a reciever which gets data, Connect this Module with 2 Led Lights (opp/adj directions). Over the course of the Project, communicaton
will take place bettween the two Esp 32s  and have to be connected to the same network.

Working:-
The Code is written in such a way that, the ESP 32 Cam captures the presence/absence of an object it updates the satus to a text file saved in a web server which updated every 20ms. This data is then read by the
Reciver module s ESP 32 which controls the traffic cycles. Once the ESP 32 Cam detects an Ambulance the data is immediately sent to the reciving module which alters the traffic cycles for a delay of atleast 5-10 sec 
higher than the default delay the traffic cycles are set to, allowing the Ambulance to pass through without any hastle.
