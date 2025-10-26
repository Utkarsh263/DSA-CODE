-- # Write your MySQL query statement below

-- WITH new_table AS (
--     SELECT 
--         d.name AS Department,
--         e.name AS Employee,
--         e.salary AS Salary,
--         DENSE_RANK() OVER(PARTITION BY d.name ORDER BY e.salary DESC) AS ranking
--     FROM Employee e
--     LEFT JOIN Department d
--     ON e.departmentId = d.id
-- )
-- SELECT Department, Employee, Salary
-- FROM new_table
-- WHERE ranking <= 3;

Select d.name as department , e1.name as employee, e1.salary as Salary
From Employee e1 join Department d on e1.DepartmentId = d.Id
Where  3 > (select count(distinct (e2.Salary))
            from  Employee e2
            where e2.Salary > e1.Salary
            and e1.DepartmentId = e2.DepartmentId)