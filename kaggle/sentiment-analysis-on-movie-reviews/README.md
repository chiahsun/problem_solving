[Kaggle page](https://www.kaggle.com/c/sentiment-analysis-on-movie-reviews)

| Solution | Private/Public Score | Standing |
| :-: | :-: | :-: |
| DNN (`SentimentAnalysisLSTM.ipynb`) | 0.61886 | 328/860 |
| LSTM bidirectional <br> (`SentimentAnalysisLSTM.ipynb`) | 0.61987 | 313/860 |
| LSTM bidirectional <br> (`SentimentAnalysisLSTM.ipynb`) <br> Use all training data | 0.63271 | 221/860 |

You can also view the [kaggle kernel](https://www.kaggle.com/chiahsun/sentiment-analysis-on-movie-reviews-lstm) since the submissions are mainly run on it with GPU. The local version is for reference.

```bash
kaggle competitions submit -c sentiment-analysis-on-movie-reviews -f final_lstm_submission.csv -m "First LSTM solution"
```
