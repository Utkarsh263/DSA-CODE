# Write your MySQL query statement below
Select id,
CASE 
    when p_id IS NULL THEN 'Root'
    when id not in (Select p_id from tree where p_id is not null) then 'Leaf'
    else 'Inner'
END AS type
from Tree;
