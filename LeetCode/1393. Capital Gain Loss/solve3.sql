SELECT DISTINCT stock_name, 
                SUM(CASE WHEN operation = 'Buy' THEN -price ELSE price END) OVER (PARTITION BY stock_name) AS capital_gain_loss
  FROM Stocks
