library(readr)

train <- read_csv('./titanic/train.csv')
test <- read_csv('./titanic/test.csv')

table(train$Pclass)
table(test$Pclass)

summary(train$Age)
summary(test$Age)

table(train$SibSp)
table(test$SibSp)

# table(train$Ticket) # Remove Ticket
# table(train$Cabin) # Remove Cabin

# table(train$Embarked)