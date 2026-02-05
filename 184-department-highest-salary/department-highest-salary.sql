# Write your MySQL query statement below
SELECT d.name as Department,
        e.name as Employee,
        e.salary as Salary
from Employee e
JOIN department d
on e.departmentId = d.id
where (e.departmentId , e.salary) IN
(
    SELECT departmentId , MAX(salary)
    from employee
    group by departmentId
);