# T-Analyzer
A device used to analyze and detect various odour levels in rest rooms/toilets

An offensive smelling toilet is more often caused by a lack of cleaning.While regular cleaning definitely minimizes toilet odor,depending on the usage rate,the frequency in which toilet should be cleaned would varies.
In this project a solution is proposed to  analyze and detect various odour levels in rest rooms/toilets.It produces alerts at instances where the odor level exceeds the limit.The system consists of a transmitter module which is kept inside the toilet and a receiver/display module which is kept either just outside toilet or within the vicinity of cleaning staffs.

The sytem consists of various gas sensors like MQ2,MQ3,MQ6,MQ135 for detecting different gaseous componenets in the environment. The sensor values were logged for 5 hours and k-means clustering was done for classifying the values into two different regions. Depending on the average distance of the new sensor values from the centroid values,the condition in the restroom would be analyzed. Based on the different odour level detected,the display color of LED indicator placed outside the toilet changes. The communication across the transmitter and receiver module happens across NRF module. Arduino Mega was used as the main controller for the transmitter and receiver modules.
