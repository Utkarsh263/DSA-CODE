# Write your MySQL query statement below

SELECT DISTINCT num as ConsecutiveNums 
from (
    SELECT num, 
    LAG(num, 1) over() as prev1,
    LAG(num, 2) over() as prev2
    from logs
)t
where num = prev1 AND num = prev2;