# Write your MySQL query statement below
# Write your MySQL query statement below
-- SELECT Employee.name,Bonus.bonus FROM Employee 
-- LEFT JOIN Bonus ON Employee.empID = Bonus.empID
-- WHERE bonus < 1000 OR Bonus IS NULL ;


select employee.name , Bonus.bonus from employee
left join bonus on employee.empid = Bonus.empid
where bonus < 1000 or bonus is null;