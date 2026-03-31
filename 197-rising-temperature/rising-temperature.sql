# Write your MySQL query statement below
SELECT w.id as Id from Weather w
JOIN 
Weather we 
on  DATEDIFF(w.recordDate , we.recordDate) = 1
where w.temperature > we.temperature;