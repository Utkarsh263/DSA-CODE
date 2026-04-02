# Write your MySQL query statement below
Select w.id from weather w
Join 
Weather we
on DATEDIFF(w.recordDate , we.recordDate) = 1
where w.temperature > we.temperature;