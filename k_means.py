__author__ = 'RAJMOHAN'
import numpy as np
from sklearn import cross_validation,preprocessing,neighbors
import pandas as pd
import quandl
import math
from sklearn.cluster import KMeans
#from sklearn import Kmeans

data = pd.read_csv('sensor.txt')
#data.replace('?',-99999,inplace=True)
#data.drop('id', 1, inplace = True)

#Just for show, let's show what happens when we do indeed include truly meaningless and misleading data by commenting out the dropping of the id column
#VERY VERY IMPORTANT   !!!!9



X= np.array(data.drop('class',1))
y=np.array(data['class'])

X_train,X_test,y_train,y_test=cross_validation.train_test_split(X,y,test_size=0.2)
#classifier=neighbors.KNeighborsClassifier()
classifier=KMeans(n_clusters=2,random_state=None)

classifier.fit(X_train,y_train)
accuracy=classifier.score(X_test,y_test)



examples = np.array([[4,2,1,1,1,2,3,2,1],[4,2,1,1,1,2,3,2,1]])
examples_final = examples.reshape(len(examples), -1)
predicted_value = classifier.predict(examples_final)

print predicted_value
print classifier.cluster_centers_