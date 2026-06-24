# Write your MySQL query statement below
SELECT w1.id 
FROM Weather w
JOIN
Weather w1 
WHERE w1.temperature > w.temperature AND 
DATEDIFF(w1.recordDate , w.recordDate) = 1