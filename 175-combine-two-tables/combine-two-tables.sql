# Write your MySQL query statement below
SELECT p.firstName , p.lastName , c.city, c.state
from person p
LEFT JOIN address c
on p.personID = c.personID;