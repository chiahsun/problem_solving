# Tensorflow Dataset (sentiment140)

[Catalog for sentiment140](https://www.tensorflow.org/datasets/catalog/sentiment140)


```python
# https://www.tensorflow.org/datasets/overview?hl=zh-tw

import tensorflow as tf

keras = tf.keras
tf.__version__
```




    '2.5.0'



# Prepare Data


```python
import tensorflow_datasets as tfds

# https://www.tensorflow.org/datasets/splits?hl=zh-tw
# https://www.tensorflow.org/datasets/overview?hl=zh-tw#as_tuple_as_supervisedtrue

# train_ds, valid_ds = tfds.load('sentiment140', split = ['train', 'test'])
train_ds = tfds.load('sentiment140', split = 'train[0:5%]', as_supervised = True)
valid_ds = tfds.load('sentiment140', split = 'train[5%:6%]', as_supervised = True)
test_ds = tfds.load('sentiment140', split = 'train[-20:]', as_supervised = True)
```


```python
train_ds
```




    <PrefetchDataset shapes: ((), ()), types: (tf.string, tf.int32)>




```python
# https://www.tensorflow.org/api_docs/python/tf/data/Dataset#take
for text, label in train_ds.take(1):
    print(text)
    print(label)
    print(text.numpy().decode('utf-8'))
```

    tf.Tensor(b"i'm 10x cooler than all of you! ", shape=(), dtype=string)
    tf.Tensor(4, shape=(), dtype=int32)
    i'm 10x cooler than all of you! 



```python
lines = [text.numpy().decode('utf-8') for text, _ in train_ds]
lines[0]
```




    "i'm 10x cooler than all of you! "




```python
word_set = set()

for l in lines:
    for w in l.split(' '):
        word_set.add(w)
    
VOCAB_SIZE = len(word_set)   
VOCAB_SIZE
```




    146196




```python
for index, w in enumerate(word_set):
    if index >= 10:
        break
    print(f'{index:3}: {w}')
```

      0: 
      1: fruits
      2: whose
      3: terrified.
      4: @therealpharrell
      5: kum
      6: workplace
      7: @SheriSalata,
      8: @mattskint
      9: twitter...



```python
from tensorflow.keras.preprocessing.text import Tokenizer

tokenizer = Tokenizer(num_words = VOCAB_SIZE, oov_token = '<OOV>')
tokenizer.fit_on_texts(lines)
word_index = tokenizer.word_index
for index, (a, b) in enumerate(word_index.items()):
    if index >= 5:
        break
    print(a, b)
```

    <OOV> 1
    i 2
    to 3
    the 4
    a 5



```python
maxlen = 0
cnt = 0

# If batch_size cannot divide total size, the remainder will be skipped
for text_batch, label in train_ds.batch(1):
    text_batch = map(lambda text: text.numpy().decode('utf-8'), text_batch)
    sequences = tokenizer.texts_to_sequences(text_batch)
    len_of_sequences = list(map(len, sequences))
    maxlen = max(maxlen, *len_of_sequences)
    cnt = cnt + 1

print(cnt)
maxlen
```

    80000





    36




```python
from tensorflow.keras.preprocessing.sequence import pad_sequences

def tokenize_and_pad(text_batch, label_batch):
    text_batch = map(lambda s: s.numpy().decode('utf-8'), text_batch)
    sequences = tokenizer.texts_to_sequences(text_batch)
    padded = pad_sequences(sequences, 
                           maxlen = maxlen, 
                           padding ='post', 
                           truncating = 'post')
    return padded, label_batch

for text_batch, label_batch in train_ds.batch(2).take(1):
    text_batch, label_batch = tokenize_and_pad(text_batch, label_batch)
    print(text_batch)
    print('\n')
    print(label_batch)
    print('\n\n')
    print(text_batch.shape, label_batch.shape)
```

    [[   20 11880  3026   199    32    13     8     0     0     0     0     0
          0     0     0     0     0     0     0     0     0     0     0     0
          0     0     0     0     0     0     0     0     0     0     0     0]
     [  321  4307   282   686     2   174   374   444   149    14   103     2
         17  1772    13   149     3  2851     0     0     0     0     0     0
          0     0     0     0     0     0     0     0     0     0     0     0]]
    
    
    tf.Tensor([4 0], shape=(2,), dtype=int32)
    
    
    
    (2, 36) (2,)



```python
import numpy as np

def get_dataset_from_original_ds(ds, batch_size = 32, max_index = None):
    text_batch_slices = []
    label_batch_slices = []
    for index, (text_batch, label_batch) in enumerate(ds.batch(2)):
        if (max_index != None) and (index >= max_index):
            break
        text_batch, label_batch = tokenize_and_pad(text_batch, label_batch)
        text_batch_slices.append(text_batch)
        label_batch_slices.append(label_batch)
    text_slices = np.concatenate(text_batch_slices)
    label_slices = np.concatenate(label_batch_slices)
    
    # https://stackoverflow.com/questions/65230657/tensorflow-how-to-create-a-dataset-which-is-an-array-of-tuples
    return tf.data.Dataset.from_tensor_slices((text_slices, label_slices)).batch(batch_size).prefetch(1)

ds = get_dataset_from_original_ds(train_ds, max_index = 2)
sample_x = None
for x, y in ds:
    sample_x = x
    print(x.shape, ' -> ', y.shape)
    print(x, ' -> ', y, end = '\n\n')
    
print(sample_x.numpy().shape)
sample_x.numpy()
```

    (4, 36)  ->  (4,)
    tf.Tensor(
    [[   20 11880  3026   199    32    13     8     0     0     0     0     0
          0     0     0     0     0     0     0     0     0     0     0     0
          0     0     0     0     0     0     0     0     0     0     0     0]
     [  321  4307   282   686     2   174   374   444   149    14   103     2
         17  1772    13   149     3  2851     0     0     0     0     0     0
          0     0     0     0     0     0     0     0     0     0     0     0]
     [   56     5   305    31    25     3    49     3     6   173   434     0
          0     0     0     0     0     0     0     0     0     0     0     0
          0     0     0     0     0     0     0     0     0     0     0     0]
     [24058    66     2    26    21   754     3 24059   313   378    60   233
        995     3    58    26    11 15380  3027     8  4521     6   897     0
          0     0     0     0     0     0     0     0     0     0     0     0]], shape=(4, 36), dtype=int32)  ->  tf.Tensor([4 0 4 4], shape=(4,), dtype=int32)
    
    (4, 36)





    array([[   20, 11880,  3026,   199,    32,    13,     8,     0,     0,
                0,     0,     0,     0,     0,     0,     0,     0,     0,
                0,     0,     0,     0,     0,     0,     0,     0,     0,
                0,     0,     0,     0,     0,     0,     0,     0,     0],
           [  321,  4307,   282,   686,     2,   174,   374,   444,   149,
               14,   103,     2,    17,  1772,    13,   149,     3,  2851,
                0,     0,     0,     0,     0,     0,     0,     0,     0,
                0,     0,     0,     0,     0,     0,     0,     0,     0],
           [   56,     5,   305,    31,    25,     3,    49,     3,     6,
              173,   434,     0,     0,     0,     0,     0,     0,     0,
                0,     0,     0,     0,     0,     0,     0,     0,     0,
                0,     0,     0,     0,     0,     0,     0,     0,     0],
           [24058,    66,     2,    26,    21,   754,     3, 24059,   313,
              378,    60,   233,   995,     3,    58,    26,    11, 15380,
             3027,     8,  4521,     6,   897,     0,     0,     0,     0,
                0,     0,     0,     0,     0,     0,     0,     0,     0]],
          dtype=int32)




```python
final_train_ds = get_dataset_from_original_ds(train_ds)
final_valid_ds = get_dataset_from_original_ds(valid_ds)
final_train_ds.element_spec
```




    (TensorSpec(shape=(None, 36), dtype=tf.int32, name=None),
     TensorSpec(shape=(None,), dtype=tf.int32, name=None))



# Build Model


```python
tf.random.set_seed(1)
np.random.seed(1)
model = keras.Sequential([
    keras.layers.Embedding(VOCAB_SIZE, 16, input_length = maxlen),
    keras.layers.Flatten(),
    keras.layers.Dense(6, activation = 'relu'),
    keras.layers.Dense(5),
])

model.compile(
    optimizer = 'adam',
    loss = keras.losses.SparseCategoricalCrossentropy(from_logits = True),
    metrics = ['accuracy'],
)
model.summary()
```

    Model: "sequential"
    _________________________________________________________________
    Layer (type)                 Output Shape              Param #   
    =================================================================
    embedding (Embedding)        (None, 36, 16)            2339136   
    _________________________________________________________________
    flatten (Flatten)            (None, 576)               0         
    _________________________________________________________________
    dense (Dense)                (None, 6)                 3462      
    _________________________________________________________________
    dense_1 (Dense)              (None, 5)                 35        
    =================================================================
    Total params: 2,342,633
    Trainable params: 2,342,633
    Non-trainable params: 0
    _________________________________________________________________



```python
early_stopping = keras.callbacks.EarlyStopping(
    patience = 5,
    restore_best_weights = True,
)

history = model.fit(
    final_train_ds,
    epochs = 500,
    validation_data = (final_valid_ds),
    callbacks = [early_stopping],
    # verbose = 0,
)
```

    Epoch 1/500
    2500/2500 [==============================] - 26s 10ms/step - loss: 0.5630 - accuracy: 0.7198 - val_loss: 0.4964 - val_accuracy: 0.7614
    Epoch 2/500
    2500/2500 [==============================] - 26s 10ms/step - loss: 0.3513 - accuracy: 0.8539 - val_loss: 0.5597 - val_accuracy: 0.7487
    Epoch 3/500
    2500/2500 [==============================] - 26s 10ms/step - loss: 0.1941 - accuracy: 0.9253 - val_loss: 0.6777 - val_accuracy: 0.7363
    Epoch 4/500
    2500/2500 [==============================] - 25s 10ms/step - loss: 0.1079 - accuracy: 0.9613 - val_loss: 0.8167 - val_accuracy: 0.7302
    Epoch 5/500
    2500/2500 [==============================] - 25s 10ms/step - loss: 0.0628 - accuracy: 0.9780 - val_loss: 0.9855 - val_accuracy: 0.7230
    Epoch 6/500
    2500/2500 [==============================] - 26s 10ms/step - loss: 0.0386 - accuracy: 0.9868 - val_loss: 1.1640 - val_accuracy: 0.7156


# Predict on Test Data


```python
final_test_ds = get_dataset_from_original_ds(test_ds)
```


```python
predicted = map(tf.argmax, model.predict(final_test_ds))
predicted = list(map(lambda x: x.numpy(), predicted))
print(predicted)
```

    [4, 0, 0, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4]



```python
import pandas as pd

xs, ys = [], []

for x, _ in test_ds:
    xs.append(x.numpy().decode('utf-8')) 
    
for _, y in final_test_ds:
    ys.append(y.numpy())

real = np.concatenate(ys)

pd.set_option('display.max_colwidth', None)
df = pd.DataFrame({'real': real, 'predicted': predicted, 'text': xs})
# https://stackoverflow.com/questions/25351968/how-can-i-display-full-non-truncated-dataframe-information-in-html-when-conver
with pd.option_context('display.max_colwidth', -1):     
    display(df)
```


<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

    .dataframe tbody tr th {
        vertical-align: top;
    }

    .dataframe thead th {
        text-align: right;
    }
</style>
<table border="1" class="dataframe">
  <thead>
    <tr style="text-align: right;">
      <th></th>
      <th>real</th>
      <th>predicted</th>
      <th>text</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>0</th>
      <td>4</td>
      <td>4</td>
      <td>@allygodinez How was the meet &amp;amp; greet?</td>
    </tr>
    <tr>
      <th>1</th>
      <td>0</td>
      <td>0</td>
      <td>off to the malll ; i really dont want to do swimming in gym tomorrow</td>
    </tr>
    <tr>
      <th>2</th>
      <td>0</td>
      <td>0</td>
      <td>chemistry revision is absolute balls</td>
    </tr>
    <tr>
      <th>3</th>
      <td>4</td>
      <td>4</td>
      <td>heading out to CA where the waether looks sunny</td>
    </tr>
    <tr>
      <th>4</th>
      <td>4</td>
      <td>4</td>
      <td>Ate subway yum</td>
    </tr>
    <tr>
      <th>5</th>
      <td>4</td>
      <td>4</td>
      <td>@NKAirplay That gives me visions of a Wahlberg sandwich.</td>
    </tr>
    <tr>
      <th>6</th>
      <td>4</td>
      <td>4</td>
      <td>@brighit Says it's 'unavailable'-i'll have a look on Boombox</td>
    </tr>
    <tr>
      <th>7</th>
      <td>4</td>
      <td>4</td>
      <td>Watchin charm school  @lalavazquez @riskybizness23  looooove you guys</td>
    </tr>
    <tr>
      <th>8</th>
      <td>4</td>
      <td>4</td>
      <td>I am also being a lazy bum this morning and currently sat with Pjs on and cuppa watching said rain while twittering  ahhhhh bliss......</td>
    </tr>
    <tr>
      <th>9</th>
      <td>0</td>
      <td>0</td>
      <td>Watching HGTV on DVD before I go to work.  I don't wanna go anywhere</td>
    </tr>
    <tr>
      <th>10</th>
      <td>0</td>
      <td>0</td>
      <td>@AK618 ...fans starting asking for his autograph and he had to sign for them too. and he was not happy at all. I felt bad...</td>
    </tr>
    <tr>
      <th>11</th>
      <td>0</td>
      <td>0</td>
      <td>@Jessicaveronica haha what a dumbass.... People lie about the stupidest shit!! My fam lives in Houston but I'm not there, sorry!</td>
    </tr>
    <tr>
      <th>12</th>
      <td>0</td>
      <td>0</td>
      <td>I got million mental and physical things to do  would 24 hours be enough?</td>
    </tr>
    <tr>
      <th>13</th>
      <td>4</td>
      <td>0</td>
      <td>@Jasmine1993 i have attempted and it didnt go to well hehe i might have another go soon though</td>
    </tr>
    <tr>
      <th>14</th>
      <td>0</td>
      <td>0</td>
      <td>@GertieGamer Still a bit rubbish  decided to stay home today. Bit fed up.</td>
    </tr>
    <tr>
      <th>15</th>
      <td>0</td>
      <td>0</td>
      <td>@nicolerichie I too sleep diagonally with my boyfriend.  In my defense, he steals the covers!</td>
    </tr>
    <tr>
      <th>16</th>
      <td>4</td>
      <td>4</td>
      <td>@Leah923 &amp;quot;Yeah Eric&amp;quot; is an inside joke that only 1 percent of the listeners get (and none in syndication) but it always cracks us up!</td>
    </tr>
    <tr>
      <th>17</th>
      <td>4</td>
      <td>4</td>
      <td>@cswtham Growl is a kind of notification thing. So, when someone starts chatting, a notification pops up on screen. It's fine to get</td>
    </tr>
    <tr>
      <th>18</th>
      <td>0</td>
      <td>4</td>
      <td>A coffee and some formula diet pulver is a good start into a week. Why diet drink? If I will get a permanent job I have to loose 9 kilos</td>
    </tr>
    <tr>
      <th>19</th>
      <td>4</td>
      <td>4</td>
      <td>@rodney91 http://twitpic.com/4i3g6 - i love that game  xxxx</td>
    </tr>
  </tbody>
</table>
</div>


# Reference

[UD187 Intro to TensorFlow for Deep Learning - Lession 9: NLP Tokenization and Embedding](https://classroom.udacity.com/courses/ud187)
