# Write your MySQL query statement below
SELECT stock_name, sell_total - buy_total AS capital_gain_loss
FROM (
    SELECT * FROM (SELECT stock_name, SUM(price) as buy_total
    FROM Stocks
    WHERE operation LIKE 'Buy'
    GROUP BY stock_name) AS Buys
    INNER JOIN
    (SELECT stock_name, SUM(price) as sell_total
    FROM Stocks
    WHERE operation LIKE 'Sell'
    GROUP BY stock_name) AS Sells
    USING (stock_name) ) AS sub_query;

