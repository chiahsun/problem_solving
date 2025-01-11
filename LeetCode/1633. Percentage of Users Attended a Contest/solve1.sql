# Write your MySQL query statement below
SELECT contest_id, ROUND(100 * count / total, 2) as percentage
FROM (SELECT contest_id, COUNT(*) as count
FROM Users AS U
JOIN Register AS R
ON U.user_id = R.user_id
GROUP BY contest_id) AS T1
CROSS JOIN (SELECT COUNT(*) as total FROM Users) AS T2
ORDER BY percentage DESC, contest_id;
