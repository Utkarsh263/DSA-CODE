# Write your MySQL query statement below
SELECT id, 
CASE
    WHEN p_id IS NULL then 'Root'
    WHEN id not in (SELECT p_id from Tree where p_id is NOT NULL) then 'Leaf'
    ELSE 'Inner'
END AS type
from Tree;