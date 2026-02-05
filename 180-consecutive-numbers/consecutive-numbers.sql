# Write your MySQL query statement below
SELECT DISTINCT num as ConsecutiveNums
from(
    SELECT num,
    LAG(num, 1) over() as prev1,
    LAG(num, 2) over() as prev2
    from Logs
)t 
where num=prev1 and num=prev2;