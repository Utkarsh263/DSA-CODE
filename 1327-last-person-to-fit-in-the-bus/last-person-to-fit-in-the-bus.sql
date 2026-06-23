# Write your MySQL query statement below

SELECT person_name
FROM (
    SELECT *, SUM(weight) OVER(ORDER BY turn) as Rolling_Sum
    FROM Queue
)t
WHERE Rolling_Sum <= 1000 
ORDER BY Rolling_Sum DESC
LIMIT 1