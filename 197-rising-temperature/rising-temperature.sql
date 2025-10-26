# Write your MySQL query statement below
-- select  today.id from weather yesterday 
-- cross join weather today
-- where datediff(today.recorddate, yesterday.recorddate)=1 
-- and today.temprature > yesterday.temprature;

SELECT today.id
FROM Weather yesterday 
CROSS JOIN Weather today

WHERE DATEDIFF(today.recordDate,yesterday.recordDate) = 1
    AND today.temperature > yesterday.temperature
;