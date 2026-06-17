# Write your MySQL query statement below
SELECT w1.id as Id from weather w 
JOIN 
weather w1 
where w1.temperature > w.temperature 
AND DATEDIFF(w1.recordDate , w.recordDate) = 1;