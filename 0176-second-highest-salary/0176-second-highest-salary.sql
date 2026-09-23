# Write your MySQL query statement below
/*create table Employee(
    id int,
    salary int
);
*/

SELECT (
    SELECT salary 
    FROM (
        SELECT salary, 
               DENSE_RANK() OVER (ORDER BY salary DESC) AS ranking
        FROM Employee
    ) AS RankedTable
    WHERE ranking = 2
    LIMIT 1
) AS SecondHighestSalary;
