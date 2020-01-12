clear
clc
clf
load "savings.txt";
plot (savings(:,1), 'linewidth',1,savings(:,2), 'linewidth',2, 'y--');
hold on;
plot (savings(:,1), 'linewidth',1,savings(:,3), 'linewidth',2, 'r:');
title ('College Savings');
legend('Average Savings Account', '529 Plan');
xlabel('Months');
ylabel('Dollars');
display ("Total savings for Savings Account option:" )
format bank;
savings(end,2)
display ("Total savings for 529 PLan Option:")
format bank; 
savings (end,3) 