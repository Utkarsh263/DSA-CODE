# Write your MySQL query statement below
SELECT d.name as Department,
        e.name as Employee,
        e.salary as Salary
From Employee e
JOIN department d
on e.departmentId = d.id
where (e.departmentId , e.salary) IN
(
    Select departmentId , MAX(salary)
    from Employee
    group by departmentId
)