# Write your MySQL query statement below
DELETE P1 
FROM person p1
JOIN person p2
on p1.email = p2.email 
where p1.id > p2.id;