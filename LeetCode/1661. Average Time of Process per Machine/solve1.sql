# Write your MySQL query statement below
SELECT A1.machine_id, ROUND(AVG(A2.timestamp - A1.timestamp), 3) AS processing_time # A1.machine_id, A1.process_id, A1.timestamp as start, A2.timestamp as end
FROM Activity A1, Activity A2
WHERE A1.machine_id = A2.machine_id AND A1.process_id = A2.process_id AND A1.activity_type = 'start' AND A2.activity_type = 'end'
GROUP BY A1.machine_id;
