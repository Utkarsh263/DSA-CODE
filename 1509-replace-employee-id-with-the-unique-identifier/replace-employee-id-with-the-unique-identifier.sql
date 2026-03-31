# Write your MySQL query statement below
SELECT em.unique_id , e.name from 
Employees e
LEFT JOIN 
EmployeeUNI em
on e.id = em.id;