import 'hardhat/console.sol';


pragma solidity ^0.5.1;

contract Transact{
    mapping (address=>userDetails) Details; // Maps address to user balance address[] allUsers; // Stores address of every different user as an array struct userDetails{
    address _address; uint balance;
    uint min; //Max withdrawal limit uint start;
}

address public owner;


constructor() public{ owner=msg.sender;
}
uint public total=0;// Stores net balance of contract




function deposit() payable public
{
  Details[msg.sender]=userDetails(msg.sender,msg.value,msg.value/100,block.timestamp); allUsers.push(msg.sender);
  total+=msg.value;
} //Registers User as depositor and records value




function withdrawUser(uint val) public { require (Details[msg.sender].balance>0);
require (Details[msg.sender].start-block.timestamp>=1 days); // This is not restricting in Remix , used now too
if (val>Details[msg.sender].min)
{
  console.log("Daily withdrawal Value exceeds 1% of deposit."); console.log("%d",Details[msg.sender].start-block.timestamp);
}
else
{
  msg.sender.transfer(val); Details[msg.sender].balance-=val; total-=val;
  Details[msg.sender].start=block.timestamp;
}


}




function withdrawOwner() public{ require(msg.sender==owner); msg.sender.transfer(total); total=0;
for (uint i=0;i<allUsers.length;i++)

Details[allUsers[i]].balance=0;

}
