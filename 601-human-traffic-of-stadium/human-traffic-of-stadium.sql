# Write your MySQL query statement below
-- WITH cte as (
--     SELECT * , id - ROW_NUMBER() over (order by id) as 'grp'
--     FROM Stadium
--     where people >= 100
-- )

-- SELECT id , visit_date , people
-- FROM cte
-- where grp in (
--     SELECT grp from cte
--     group by grp 
--     having count(*) >= 3
-- )
-- order by visit_date;

WITH cte as (
    SELECT * , id-ROW_NUMBER() over (Order by id) as 'grp'
    from Stadium
    where people >= 100
)

SELECT id, visit_date , people
from cte 
where grp in (
    SELECT grp 
    from cte 
    group by grp
    having count(*) >= 3
)
Order by visit_date;