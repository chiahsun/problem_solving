# Write your MySQL query statement below
# https://dev.mysql.com/doc/refman/8.4/en/regexp.html
SELECT patient_id, patient_name, conditions
FROM Patients
WHERE conditions REGEXP '^DIAB1\| DIAB1';
