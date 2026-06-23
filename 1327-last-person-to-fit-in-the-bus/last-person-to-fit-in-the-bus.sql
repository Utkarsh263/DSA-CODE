# Write your MySQL query statement below
SELECT person_name FROM(
    SELECT *, SUM(weight) OVER(ORDER BY turn) as cum_sum
    FROM Queue
)t
WHERE cum_sum <= 1000
ORDER BY cum_sum DESC
LIMIT 1
