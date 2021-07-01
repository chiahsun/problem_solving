library(readr)

# https://en.wikipedia.org/wiki/Titanic
train <- read_csv('./titanic/train.csv')
test <- read_csv('./titanic/test.csv')

# https://www.encyclopedia-titanica.org/titanic-survivor/amelia-icard.html
train[train$Ticket == 113572,]

tmpTest <- test
tmpTest$Survived <- NA

df <- rbind(train, tmpTest)

A <- df

# A$title <- unlist(strsplit(trimws(unlist(strsplit(df$Name, ",")[1])[2]), " "))[1]
A$title <- sapply(strsplit(trimws(sapply(strsplit(df$Name, ","), function(x) x[2])), " "), function(x) x[1])
table(A$title)

library(ggplot2)
ggplot(A, aes(x = title)) + geom_bar(aes(col = as.factor(Survived)))

A[A$title=="Capt.",]

B <- A
B$FirstName <- sapply(strsplit(df$Name, ","), function(x) x[1])
B[B$FirstName=="Crosby",]
tmp <- B[B$PassengerId %in% c(541, 746, 1197),]

# B[B$title == 'Col.',]

# TODO: make other table(s) for parent/child spouse/sibling relations
library(data.table)
l <- list()
l[[1]] <- list(PassengerId = 541, Parent = 746)
l[[2]] <- list(PassengerId = 541, Parent = 1197)
ParTable <- rbindlist(l)

l <- list()
l[[1]] <- list(PassengerId = 746, Ch = 541)
l[[2]] <- list(PassengerId = 1197, Ch = 541)
ChTable <- rbindlist(l)

tmp2 <- B[B$FirstName == 'Astor',]

l <- list()
l[[1]] <- list(PassengerId = 701, Sp = 1094)
l[[2]] <- list(PassengerId = 1094, Sp = 701)
SpTable <- rbindlist(l)

library(dplyr)
C <- B
C <- C %>%
  group_by(Ticket) %>%
  mutate(TickerCount = n()) %>%
  ungroup() %>%
  mutate(FarePer = Fare/TickerCount, .after="Fare")


# C[C$PassengerId == 541,]$ParList <- list(c(746, 1197))
# Merge train and test first

# Can we deduce the parent/child sibling/spouse relationship from the data?
# Cabin meaning
# How fare changing, its distribution?
# NA meaning? Meaningful way to fill NA?
# Ticker number meaning?
# The same ticket number meaning?
# Embarked <-> ticker number?
# Is pClass reasonable from all data?
# Label: Child. People whose age is less than ... . (Some of them Sibsp & Parch equals 0)
# Title: Master, Miss, Mr. Mrs.

# Fare divide by ticket is average value per person
# Why some ticket maps to different cabin? Can we deduce cabin?

# Can we deduce information left in test set?

# table(train$Pclass)
# table(test$Pclass)

# summary(train$Age)
# summary(test$Age)

# table(train$SibSp)
# table(test$SibSp)

# table(train$Ticket) # Remove Ticket
# table(train$Cabin) # Remove Cabin

# table(train$Embarked)