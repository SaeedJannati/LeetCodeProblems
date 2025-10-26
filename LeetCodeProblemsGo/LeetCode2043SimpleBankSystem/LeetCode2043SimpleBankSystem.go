package LeetCode2043SimpleBankSystem

type Bank struct {
	balances []int64
	size     int
}

func Constructor(balance []int64) Bank {
	size := len(balance)
	return Bank{balances: balance, size: size}
}

func (this *Bank) Transfer(account1 int, account2 int, money int64) bool {
	if account1 > this.size || account2 > this.size {
		return false
	}
	if this.balances[account1-1] < money {
		return false
	}
	this.balances[account1-1] -= money
	this.balances[account2-1] += money
	return true
}

func (this *Bank) Deposit(account int, money int64) bool {
	if account > this.size {
		return false
	}
	this.balances[account-1] += money
	return true
}

func (this *Bank) Withdraw(account int, money int64) bool {
	if account > this.size {
		return false
	}
	if this.balances[account-1] < money {
		return false
	}
	this.balances[account-1] -= money
	return true
}
