```python
import tensorflow as tf

tf.__version__
```




    '2.5.0'




```python
import pandas as pd

train = pd.read_csv('./input/fashion-mnist/fashion-mnist_train.csv')
test = pd.read_csv('./input/fashion-mnist/fashion-mnist_test.csv')
```


```python
df = train.copy()

train = df.sample(frac = 0.7, random_state = 0)
valid = df.drop(train.index)
```


```python
def split_feature_label(df):
    X = df.copy()
    y = X.pop('label')
    return X, y
    
X_train, y_train = split_feature_label(train)
X_valid, y_valid = split_feature_label(valid)
X_test, y_test = split_feature_label(test)
```


```python
X_train.iloc[0][0:15]
```




    pixel1       0
    pixel2       0
    pixel3       0
    pixel4       0
    pixel5       0
    pixel6       0
    pixel7       0
    pixel8       0
    pixel9       0
    pixel10      0
    pixel11     41
    pixel12    120
    pixel13    128
    pixel14    127
    pixel15    121
    Name: 3048, dtype: int64




```python
X_train /= 255.0
```


```python
X_train.iloc[0][0:15]
```




    pixel1     0.000000
    pixel2     0.000000
    pixel3     0.000000
    pixel4     0.000000
    pixel5     0.000000
    pixel6     0.000000
    pixel7     0.000000
    pixel8     0.000000
    pixel9     0.000000
    pixel10    0.000000
    pixel11    0.160784
    pixel12    0.470588
    pixel13    0.501961
    pixel14    0.498039
    pixel15    0.474510
    Name: 3048, dtype: float64




```python
X_train.shape[1]
```




    784




```python
X_valid /= 255.0
X_test /= 255.0
```


```python
from tensorflow.keras import callbacks

early_stopping = callbacks.EarlyStopping(
    patience = 5,
    min_delta = 0.001,
    restore_best_weights = True,
)
```


```python
# val_accuracy: 0.9167
"""
model = keras.Sequential([
    layers.Reshape((28, 28, 1), input_shape = (784, )),
    layers.Conv2D(32, (3, 3), padding = 'same', activation = 'relu'),
    layers.MaxPool2D((2, 2), strides = 2),
    layers.Flatten(),
    layers.Dense(128, activation = 'relu'),
    layers.Dense(10, activation = 'softmax'),
])
"""
```




    "\nmodel = keras.Sequential([\n    layers.Reshape((28, 28, 1), input_shape = (784, )),\n    layers.Conv2D(32, (3, 3), padding = 'same', activation = 'relu'),\n    layers.MaxPool2D((2, 2), strides = 2),\n    layers.Flatten(),\n    layers.Dense(128, activation = 'relu'),\n    layers.Dense(10, activation = 'softmax'),\n])\n"




```python
from tensorflow import keras
from keras import layers

model = keras.Sequential([
    layers.Reshape((28, 28, 1), input_shape = (784, )),
    
    layers.Conv2D(32, (3, 3), padding = 'same', activation = 'relu'),
    layers.MaxPool2D((2, 2), strides = 2),
    layers.Dropout(0.3),
    
    layers.Conv2D(64, (3, 3), padding = 'same', activation = 'relu'),
    layers.MaxPool2D((2, 2), strides = 2),
    layers.Dropout(0.3),
    
    layers.Flatten(),
    
    layers.Dense(128, activation = 'relu'),
    layers.Dropout(0.3),
    
    layers.Dense(10, activation = 'softmax'),
])

model.compile(optimizer = 'adam',
              loss = 'sparse_categorical_crossentropy',
              metrics = ['accuracy'])

history = model.fit(
    X_train, y_train,
    validation_data = (X_valid, y_valid),
    batch_size = 256,
    epochs = 500,
    callbacks = [early_stopping],
#    verbose = 0,
)
```

    Epoch 1/500
    165/165 [==============================] - 14s 83ms/step - loss: 0.7415 - accuracy: 0.7302 - val_loss: 0.4564 - val_accuracy: 0.8344
    Epoch 2/500
    165/165 [==============================] - 14s 84ms/step - loss: 0.4591 - accuracy: 0.8321 - val_loss: 0.3910 - val_accuracy: 0.8581
    Epoch 3/500
    165/165 [==============================] - 13s 81ms/step - loss: 0.4061 - accuracy: 0.8546 - val_loss: 0.3431 - val_accuracy: 0.8755
    Epoch 4/500
    165/165 [==============================] - 14s 82ms/step - loss: 0.3700 - accuracy: 0.8654 - val_loss: 0.3167 - val_accuracy: 0.8829
    Epoch 5/500
    165/165 [==============================] - 14s 87ms/step - loss: 0.3454 - accuracy: 0.8742 - val_loss: 0.3082 - val_accuracy: 0.8856
    Epoch 6/500
    165/165 [==============================] - 16s 96ms/step - loss: 0.3299 - accuracy: 0.8792 - val_loss: 0.2898 - val_accuracy: 0.8939
    Epoch 7/500
    165/165 [==============================] - 15s 93ms/step - loss: 0.3084 - accuracy: 0.8870 - val_loss: 0.2825 - val_accuracy: 0.8963
    Epoch 8/500
    165/165 [==============================] - 16s 98ms/step - loss: 0.2998 - accuracy: 0.8917 - val_loss: 0.3004 - val_accuracy: 0.8889
    Epoch 9/500
    165/165 [==============================] - 15s 94ms/step - loss: 0.2928 - accuracy: 0.8912 - val_loss: 0.2628 - val_accuracy: 0.9032
    Epoch 10/500
    165/165 [==============================] - 15s 92ms/step - loss: 0.2754 - accuracy: 0.8994 - val_loss: 0.2504 - val_accuracy: 0.9089
    Epoch 11/500
    165/165 [==============================] - 16s 96ms/step - loss: 0.2657 - accuracy: 0.9025 - val_loss: 0.2497 - val_accuracy: 0.9079
    Epoch 12/500
    165/165 [==============================] - 16s 96ms/step - loss: 0.2586 - accuracy: 0.9043 - val_loss: 0.2449 - val_accuracy: 0.9106
    Epoch 13/500
    165/165 [==============================] - 16s 95ms/step - loss: 0.2513 - accuracy: 0.9076 - val_loss: 0.2433 - val_accuracy: 0.9099
    Epoch 14/500
    165/165 [==============================] - 16s 96ms/step - loss: 0.2506 - accuracy: 0.9067 - val_loss: 0.2341 - val_accuracy: 0.9148
    Epoch 15/500
    165/165 [==============================] - 16s 95ms/step - loss: 0.2357 - accuracy: 0.9143 - val_loss: 0.2295 - val_accuracy: 0.9145
    Epoch 16/500
    165/165 [==============================] - 16s 96ms/step - loss: 0.2298 - accuracy: 0.9150 - val_loss: 0.2290 - val_accuracy: 0.9158
    Epoch 17/500
    165/165 [==============================] - 16s 96ms/step - loss: 0.2303 - accuracy: 0.9143 - val_loss: 0.2273 - val_accuracy: 0.9169
    Epoch 18/500
    165/165 [==============================] - 16s 95ms/step - loss: 0.2226 - accuracy: 0.9188 - val_loss: 0.2250 - val_accuracy: 0.9173
    Epoch 19/500
    165/165 [==============================] - 16s 96ms/step - loss: 0.2163 - accuracy: 0.9194 - val_loss: 0.2211 - val_accuracy: 0.9183
    Epoch 20/500
    165/165 [==============================] - 17s 100ms/step - loss: 0.2117 - accuracy: 0.9212 - val_loss: 0.2162 - val_accuracy: 0.9227
    Epoch 21/500
    165/165 [==============================] - 16s 98ms/step - loss: 0.2067 - accuracy: 0.9210 - val_loss: 0.2171 - val_accuracy: 0.9204
    Epoch 22/500
    165/165 [==============================] - 17s 100ms/step - loss: 0.2030 - accuracy: 0.9239 - val_loss: 0.2177 - val_accuracy: 0.9207
    Epoch 23/500
    165/165 [==============================] - 15s 91ms/step - loss: 0.1996 - accuracy: 0.9257 - val_loss: 0.2161 - val_accuracy: 0.9232
    Epoch 24/500
    165/165 [==============================] - 16s 94ms/step - loss: 0.1930 - accuracy: 0.9268 - val_loss: 0.2134 - val_accuracy: 0.9227
    Epoch 25/500
    165/165 [==============================] - 16s 94ms/step - loss: 0.1890 - accuracy: 0.9283 - val_loss: 0.2148 - val_accuracy: 0.9216
    Epoch 26/500
    165/165 [==============================] - 15s 93ms/step - loss: 0.1852 - accuracy: 0.9315 - val_loss: 0.2081 - val_accuracy: 0.9254
    Epoch 27/500
    165/165 [==============================] - 16s 94ms/step - loss: 0.1837 - accuracy: 0.9310 - val_loss: 0.2098 - val_accuracy: 0.9246
    Epoch 28/500
    165/165 [==============================] - 16s 98ms/step - loss: 0.1809 - accuracy: 0.9320 - val_loss: 0.2054 - val_accuracy: 0.9270
    Epoch 29/500
    165/165 [==============================] - 16s 95ms/step - loss: 0.1765 - accuracy: 0.9329 - val_loss: 0.2071 - val_accuracy: 0.9264
    Epoch 30/500
    165/165 [==============================] - 16s 95ms/step - loss: 0.1784 - accuracy: 0.9325 - val_loss: 0.2069 - val_accuracy: 0.9259
    Epoch 31/500
    165/165 [==============================] - 16s 95ms/step - loss: 0.1688 - accuracy: 0.9358 - val_loss: 0.2037 - val_accuracy: 0.9282
    Epoch 32/500
    165/165 [==============================] - 16s 98ms/step - loss: 0.1688 - accuracy: 0.9357 - val_loss: 0.2022 - val_accuracy: 0.9286
    Epoch 33/500
    165/165 [==============================] - 15s 94ms/step - loss: 0.1658 - accuracy: 0.9376 - val_loss: 0.2037 - val_accuracy: 0.9289
    Epoch 34/500
    165/165 [==============================] - 16s 97ms/step - loss: 0.1624 - accuracy: 0.9368 - val_loss: 0.2180 - val_accuracy: 0.9244
    Epoch 35/500
    165/165 [==============================] - 15s 93ms/step - loss: 0.1634 - accuracy: 0.9384 - val_loss: 0.2044 - val_accuracy: 0.9266
    Epoch 36/500
    165/165 [==============================] - 16s 97ms/step - loss: 0.1575 - accuracy: 0.9409 - val_loss: 0.2067 - val_accuracy: 0.9278
    Epoch 37/500
    165/165 [==============================] - 16s 95ms/step - loss: 0.1546 - accuracy: 0.9409 - val_loss: 0.2029 - val_accuracy: 0.9285



```python
max(history.history['val_accuracy'])
```




    0.92894446849823




```python
test_loss, test_acc = model.evaluate(X_test, y_test)
print(f"Test loss: {test_loss}, Test accuracy: {test_acc}")
```

    313/313 [==============================] - 3s 9ms/step - loss: 0.1971 - accuracy: 0.9271
    Test loss: 0.19712169468402863, Test accuracy: 0.9271000027656555


# Reference

[Kaggle - Intro to Deep Learning - Dropout and Batch Normalization](https://www.kaggle.com/ryanholbrook/dropout-and-batch-normalization)

[UD187 - Lession 4: Introduction to CNNs Colab](https://colab.research.google.com/github/tensorflow/examples/blob/master/courses/udacity_intro_to_tensorflow_for_deep_learning/l04c01_image_classification_with_cnns.ipynb#scrollTo=9ODch-OFCaW4)
