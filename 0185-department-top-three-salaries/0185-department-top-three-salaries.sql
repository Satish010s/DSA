# Write your MySQL query statement below
SELECT d.name AS Department,Ranked_table.name AS Employee ,Ranked_table.salary AS Salary
FROM (
    SELECT departmentId , name ,salary ,
    DENSE_RANK() OVER (PARTITION BY departmentId ORDER BY salary DESC) AS Salary_rank
    FROM Employee

) Ranked_table
JOIN Department d ON Ranked_table.departmentId =d.id
WHERE Ranked_table.Salary_rank<=3;