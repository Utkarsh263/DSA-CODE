# Write your MySQL query statement below

SELECT w1.id from Weather w 
JOIN 
Weather w1 
where w1.temperature > w.temperature 
AND DATEDIFF(w1.recordDate , w.recordDate) = 1;