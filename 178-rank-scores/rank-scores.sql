# Write your MySQL query statement below

SELECT score , DENSE_RANK() over (order by score desc) as 'rank' 
from Scores;