# Write your MySQL query statement below
SELECT email as EMAIL
from person 
group by email
having count(email) > 1;