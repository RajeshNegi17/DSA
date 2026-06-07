# Write your MySQL query statement below
SELECT uni.unique_id , e.name
FROM Employees e left join EmployeeUNI uni
ON e.id = uni.id;
