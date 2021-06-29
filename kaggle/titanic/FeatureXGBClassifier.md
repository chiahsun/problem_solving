```python
import numpy as np
import pandas as pd

train = pd.read_csv('./input/titanic/train.csv')
train.head(5)
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
      <th>PassengerId</th>
      <th>Survived</th>
      <th>Pclass</th>
      <th>Name</th>
      <th>Sex</th>
      <th>Age</th>
      <th>SibSp</th>
      <th>Parch</th>
      <th>Ticket</th>
      <th>Fare</th>
      <th>Cabin</th>
      <th>Embarked</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>0</th>
      <td>1</td>
      <td>0</td>
      <td>3</td>
      <td>Braund, Mr. Owen Harris</td>
      <td>male</td>
      <td>22.0</td>
      <td>1</td>
      <td>0</td>
      <td>A/5 21171</td>
      <td>7.2500</td>
      <td>NaN</td>
      <td>S</td>
    </tr>
    <tr>
      <th>1</th>
      <td>2</td>
      <td>1</td>
      <td>1</td>
      <td>Cumings, Mrs. John Bradley (Florence Briggs Th...</td>
      <td>female</td>
      <td>38.0</td>
      <td>1</td>
      <td>0</td>
      <td>PC 17599</td>
      <td>71.2833</td>
      <td>C85</td>
      <td>C</td>
    </tr>
    <tr>
      <th>2</th>
      <td>3</td>
      <td>1</td>
      <td>3</td>
      <td>Heikkinen, Miss. Laina</td>
      <td>female</td>
      <td>26.0</td>
      <td>0</td>
      <td>0</td>
      <td>STON/O2. 3101282</td>
      <td>7.9250</td>
      <td>NaN</td>
      <td>S</td>
    </tr>
    <tr>
      <th>3</th>
      <td>4</td>
      <td>1</td>
      <td>1</td>
      <td>Futrelle, Mrs. Jacques Heath (Lily May Peel)</td>
      <td>female</td>
      <td>35.0</td>
      <td>1</td>
      <td>0</td>
      <td>113803</td>
      <td>53.1000</td>
      <td>C123</td>
      <td>S</td>
    </tr>
    <tr>
      <th>4</th>
      <td>5</td>
      <td>0</td>
      <td>3</td>
      <td>Allen, Mr. William Henry</td>
      <td>male</td>
      <td>35.0</td>
      <td>0</td>
      <td>0</td>
      <td>373450</td>
      <td>8.0500</td>
      <td>NaN</td>
      <td>S</td>
    </tr>
  </tbody>
</table>
</div>




```python
print(train.dtypes)
```

    PassengerId      int64
    Survived         int64
    Pclass           int64
    Name            object
    Sex             object
    Age            float64
    SibSp            int64
    Parch            int64
    Ticket          object
    Fare           float64
    Cabin           object
    Embarked        object
    dtype: object



```python
def transform1(df):
    X_1 = pd.DataFrame()
    # for colname in train.select_dtypes(["category", "object"]):
    for colname in ['Sex', 'Ticket', 'Cabin', 'Embarked']:
        X_1[colname], _ = df[colname].factorize()
    return X_1

X_1 = transform1(train)
X_1
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
      <th>Sex</th>
      <th>Ticket</th>
      <th>Cabin</th>
      <th>Embarked</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>0</th>
      <td>0</td>
      <td>0</td>
      <td>-1</td>
      <td>0</td>
    </tr>
    <tr>
      <th>1</th>
      <td>1</td>
      <td>1</td>
      <td>0</td>
      <td>1</td>
    </tr>
    <tr>
      <th>2</th>
      <td>1</td>
      <td>2</td>
      <td>-1</td>
      <td>0</td>
    </tr>
    <tr>
      <th>3</th>
      <td>1</td>
      <td>3</td>
      <td>1</td>
      <td>0</td>
    </tr>
    <tr>
      <th>4</th>
      <td>0</td>
      <td>4</td>
      <td>-1</td>
      <td>0</td>
    </tr>
    <tr>
      <th>...</th>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
    </tr>
    <tr>
      <th>886</th>
      <td>0</td>
      <td>677</td>
      <td>-1</td>
      <td>0</td>
    </tr>
    <tr>
      <th>887</th>
      <td>1</td>
      <td>678</td>
      <td>145</td>
      <td>0</td>
    </tr>
    <tr>
      <th>888</th>
      <td>1</td>
      <td>614</td>
      <td>-1</td>
      <td>0</td>
    </tr>
    <tr>
      <th>889</th>
      <td>0</td>
      <td>679</td>
      <td>146</td>
      <td>1</td>
    </tr>
    <tr>
      <th>890</th>
      <td>0</td>
      <td>680</td>
      <td>-1</td>
      <td>2</td>
    </tr>
  </tbody>
</table>
<p>891 rows × 4 columns</p>
</div>




```python
def transform2(df):
    X_2 = pd.DataFrame()
    # X_2 = train.select_dtypes(['int64'])
    X_2["SibSp"] = df.SibSp
    X_2["Parch"] = df.Parch
    X_2["CompanyCount"] = df.SibSp + df.Parch
    X_2["Pclass"] = df.Pclass
    
    return X_2

X_2 = transform2(train)
X_2
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
      <th>SibSp</th>
      <th>Parch</th>
      <th>CompanyCount</th>
      <th>Pclass</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>0</th>
      <td>1</td>
      <td>0</td>
      <td>1</td>
      <td>3</td>
    </tr>
    <tr>
      <th>1</th>
      <td>1</td>
      <td>0</td>
      <td>1</td>
      <td>1</td>
    </tr>
    <tr>
      <th>2</th>
      <td>0</td>
      <td>0</td>
      <td>0</td>
      <td>3</td>
    </tr>
    <tr>
      <th>3</th>
      <td>1</td>
      <td>0</td>
      <td>1</td>
      <td>1</td>
    </tr>
    <tr>
      <th>4</th>
      <td>0</td>
      <td>0</td>
      <td>0</td>
      <td>3</td>
    </tr>
    <tr>
      <th>...</th>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
    </tr>
    <tr>
      <th>886</th>
      <td>0</td>
      <td>0</td>
      <td>0</td>
      <td>2</td>
    </tr>
    <tr>
      <th>887</th>
      <td>0</td>
      <td>0</td>
      <td>0</td>
      <td>1</td>
    </tr>
    <tr>
      <th>888</th>
      <td>1</td>
      <td>2</td>
      <td>3</td>
      <td>3</td>
    </tr>
    <tr>
      <th>889</th>
      <td>0</td>
      <td>0</td>
      <td>0</td>
      <td>1</td>
    </tr>
    <tr>
      <th>890</th>
      <td>0</td>
      <td>0</td>
      <td>0</td>
      <td>3</td>
    </tr>
  </tbody>
</table>
<p>891 rows × 4 columns</p>
</div>




```python
def transform3(df):
    X_3 = pd.DataFrame()
    
    X_3 = df.select_dtypes(['float64'])
    # print(X_3.isnull().sum())
    # https://pandas.pydata.org/pandas-docs/stable/reference/api/pandas.Series.fillna.html
    # X_3.fillna(0, inplace = True)
    return (X_3)

X_3 = transform3(train)
X_3
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
      <th>Age</th>
      <th>Fare</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>0</th>
      <td>22.0</td>
      <td>7.2500</td>
    </tr>
    <tr>
      <th>1</th>
      <td>38.0</td>
      <td>71.2833</td>
    </tr>
    <tr>
      <th>2</th>
      <td>26.0</td>
      <td>7.9250</td>
    </tr>
    <tr>
      <th>3</th>
      <td>35.0</td>
      <td>53.1000</td>
    </tr>
    <tr>
      <th>4</th>
      <td>35.0</td>
      <td>8.0500</td>
    </tr>
    <tr>
      <th>...</th>
      <td>...</td>
      <td>...</td>
    </tr>
    <tr>
      <th>886</th>
      <td>27.0</td>
      <td>13.0000</td>
    </tr>
    <tr>
      <th>887</th>
      <td>19.0</td>
      <td>30.0000</td>
    </tr>
    <tr>
      <th>888</th>
      <td>NaN</td>
      <td>23.4500</td>
    </tr>
    <tr>
      <th>889</th>
      <td>26.0</td>
      <td>30.0000</td>
    </tr>
    <tr>
      <th>890</th>
      <td>32.0</td>
      <td>7.7500</td>
    </tr>
  </tbody>
</table>
<p>891 rows × 2 columns</p>
</div>




```python
def transform4(df):
    X_4 = pd.DataFrame()
    
    X_4["FirstName"] = df.Name.str.split(",", n = 1, expand = True)[0]
    X_4["FirstName"], _ = X_4["FirstName"].factorize()
    return X_4

X_4 = transform4(train)
X_4
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
      <th>FirstName</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>0</th>
      <td>0</td>
    </tr>
    <tr>
      <th>1</th>
      <td>1</td>
    </tr>
    <tr>
      <th>2</th>
      <td>2</td>
    </tr>
    <tr>
      <th>3</th>
      <td>3</td>
    </tr>
    <tr>
      <th>4</th>
      <td>4</td>
    </tr>
    <tr>
      <th>...</th>
      <td>...</td>
    </tr>
    <tr>
      <th>886</th>
      <td>664</td>
    </tr>
    <tr>
      <th>887</th>
      <td>233</td>
    </tr>
    <tr>
      <th>888</th>
      <td>604</td>
    </tr>
    <tr>
      <th>889</th>
      <td>665</td>
    </tr>
    <tr>
      <th>890</th>
      <td>666</td>
    </tr>
  </tbody>
</table>
<p>891 rows × 1 columns</p>
</div>




```python
from sklearn.model_selection import cross_val_score
from xgboost import XGBClassifier

def score_dataset(X, y, 
                  model = XGBClassifier(use_label_encoder = False,
                                        eval_metric='mlogloss')):
    # https://scikit-learn.org/stable/modules/model_evaluation.html
    score = cross_val_score(
        model, X, y, cv = 5, scoring = "accuracy"  
    )
    return score.mean()

newX = pd.concat([transform1(train), transform2(train), transform3(train), transform4(train)], axis = 1)
score_dataset(newX, train.Survived)    
```




    0.814889209716904




```python
model = XGBClassifier(use_label_encoder = False, eval_metric='mlogloss')
model.fit(pd.concat([transform1(train), transform2(train), transform3(train), transform4(train)], axis = 1), train.Survived)
```




    XGBClassifier(base_score=0.5, booster='gbtree', colsample_bylevel=1,
                  colsample_bynode=1, colsample_bytree=1, eval_metric='mlogloss',
                  gamma=0, gpu_id=-1, importance_type='gain',
                  interaction_constraints='', learning_rate=0.300000012,
                  max_delta_step=0, max_depth=6, min_child_weight=1, missing=nan,
                  monotone_constraints='()', n_estimators=100, n_jobs=16,
                  num_parallel_tree=1, random_state=0, reg_alpha=0, reg_lambda=1,
                  scale_pos_weight=1, subsample=1, tree_method='exact',
                  use_label_encoder=False, validate_parameters=1, verbosity=None)




```python
test = pd.read_csv('./input/titanic/test.csv')
testX = pd.concat([transform1(test), transform2(test), transform3(test), transform4(test)], axis = 1)
predicted = model.predict(testX)
```


```python
output = pd.DataFrame({'PassengerId': test.PassengerId, 'Survived':  predicted})
print(output.head())

output.to_csv('feature_engineered.csv', index=False)
```

       PassengerId  Survived
    0          892         0
    1          893         0
    2          894         0
    3          895         0
    4          896         1

