#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "KeyGeneratorWrapper.h"
#include "AsymmetricWrapper.h"
#include "SymmetricWrapper.h"
#include "HashWrapper.h"
#include <QString>
#include <iostream>


namespace AlgorithmIndexParser
{
	constexpr int METHOD_BITS=4;
	constexpr int ALGORITHM_BITS=16;
	constexpr int TYPE_BITS=4;
	constexpr int LEFT_BITS=8*sizeof(int)-METHOD_BITS-ALGORITHM_BITS-TYPE_BITS;

	constexpr int validMask=0xFFFFFFFF^(0xFFFFFFFF<<(8*sizeof(int)-LEFT_BITS));
	constexpr int methodMask=0xFFFFFFFF^(0xFFFFFFFF<<(8*sizeof(int)-LEFT_BITS-TYPE_BITS-ALGORITHM_BITS));
	constexpr int algorithmMask=(0xFFFFFFFF^(0xFFFFFFFF<<(8*sizeof(int)-LEFT_BITS-TYPE_BITS)))^methodMask;
	constexpr int typeMask=validMask^(0xFFFFFFFF^(0xFFFFFFFF<<(8*sizeof(int)-LEFT_BITS-TYPE_BITS)));
}

MainWindow::MainWindow(QWidget *parent):
		QMainWindow(parent),
		ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	QStringList typeSelectionList;
	QStringList methodSelectionList;
	{
		typeSelectionList.append("哈希过程");
		typeSelectionList.append("对称过程");
		typeSelectionList.append("非对称过程");
	}
	{
		methodSelectionList.append("加密");
		methodSelectionList.append("解密");
	}
	ui->typeSelectionComboBox->addItems(typeSelectionList);
	ui->methodSelectionComboBox->addItems(methodSelectionList);

	//初始状态为Hash
	QStringList HashTypeList;
	{
		HashTypeList.append("Base64");
		HashTypeList.append("SHA3-512");
		HashTypeList.append("Whirlpool");
	}
	ui->algorithmSelectionComboBox->addItems(HashTypeList);
	QObject::connect(ui->typeSelectionComboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(AlgorithmTypeChange(int)));
	QObject::connect(ui->execButton,&QPushButton::clicked,this,&MainWindow::ClickExec);
	QObject::connect(ui->clearButton,&QPushButton::clicked,this,&MainWindow::ClickClear);

	QObject::connect(ui->quitButton,&QPushButton::clicked,this,&QApplication::quit);
}

MainWindow::~MainWindow()
{
	delete ui;
}

//!处理combobox不同选择二级菜单显示不同内容
void MainWindow::AlgorithmTypeChange(int index)
{
	QStringList SymmetricTypeList;
	QStringList AsymmetricTypeList;
	QStringList HashTypeList;
	{
		SymmetricTypeList.append("AES");
		SymmetricTypeList.append("RC6");
		SymmetricTypeList.append("TwoFish");
		SymmetricTypeList.append("Serpent");
		SymmetricTypeList.append("Salsa20");
		SymmetricTypeList.append("ChaCha20");
	}
	{
		AsymmetricTypeList.append("RSA");
	}
	{
		HashTypeList.append("Base64");
		HashTypeList.append("SHA3-512");
		HashTypeList.append("Whirlpool");
	}

	if(index==0)
	{
		if(ui->methodSelectionComboBox->count()==3)
			ui->methodSelectionComboBox->removeItem(2);
		ui->algorithmSelectionComboBox->clear();
		ui->algorithmSelectionComboBox->addItems(HashTypeList);
	}
	else if(index==1)
	{
		if(ui->methodSelectionComboBox->count()==2)
			ui->methodSelectionComboBox->addItem("生成密钥");
		ui->algorithmSelectionComboBox->clear();
		ui->algorithmSelectionComboBox->addItems(SymmetricTypeList);
	}
	else if(index==2)
	{
		if(ui->methodSelectionComboBox->count()==2)
			ui->methodSelectionComboBox->addItem("生成密钥");
		ui->algorithmSelectionComboBox->clear();
		ui->algorithmSelectionComboBox->addItems(AsymmetricTypeList);
	}
}

//!处理exec按键的响应
void MainWindow::ClickExec()
{
	//根据输入选择执行命令的序号
	int commandIndex=(ui->typeSelectionComboBox->currentIndex()+1)<<AlgorithmIndexParser::ALGORITHM_BITS;
	commandIndex+=ui->algorithmSelectionComboBox->currentIndex()+1;
	commandIndex<<=AlgorithmIndexParser::METHOD_BITS;
	commandIndex+=ui->methodSelectionComboBox->currentIndex()+1;

	std::string input=ui->inputTextEdit->toPlainText().toStdString();
	std::string keyt1=ui->keyt1TextEdit->toPlainText().toStdString();
	std::string keyt2=ui->keyt2TextEdit->toPlainText().toStdString();

	QString output;
	std::string tmpOutput=process(commandIndex,input,keyt1,keyt2);
	output=QString::fromStdString(tmpOutput);
	ui->outputTextEdit->setPlainText(output);
}

//!处理clear按键的响应
void MainWindow::ClickClear()
{
	ui->inputTextEdit->clear();
	ui->keyt1TextEdit->clear();
	ui->keyt2TextEdit->clear();
	ui->outputTextEdit->clear();
}

std::string process(int commandIndex,const std::string &text,const std::string &keyt1,const std::string &keyt2)
{
	std::string result;

	using namespace AlgorithmIndexParser;
	commandIndex&=validMask;//去除高位


	int methodIndex=commandIndex&methodMask;
	int algorithmIndex=(commandIndex&algorithmMask)>>METHOD_BITS;
	int typeIndex=(commandIndex&typeMask)>>(METHOD_BITS+ALGORITHM_BITS);

	using namespace CryptoppWrapper;
	if(methodIndex==3)//处理密钥生成
	{
		std::string Key1,Key2;//对称下为Key/IV,非对称下为publ/priv;
		std::string Key1Prefix,Key2Prefix;
		if(typeIndex==2)//对称
		{
			Key1Prefix="Key: ";
			Key2Prefix="iv: ";
			switch(algorithmIndex)
			{
				case 1://AES
				{
					Key1=std::get<0>(AESKeyGenerator());
					Key2=std::get<1>(AESKeyGenerator());
					break;
				}
				case 2://RC6
				{
					Key1=std::get<0>(RC6KeyGenerator());
					Key2=std::get<1>(RC6KeyGenerator());
					break;
				}
				case 3://TwoFish
				{
					Key1=std::get<0>(TwoFishKeyGenerator());
					Key2=std::get<1>(TwoFishKeyGenerator());
					break;
				}
				case 4://Serpent
				{
					Key1=std::get<0>(SerpentKeyGenerator());
					Key2=std::get<1>(SerpentKeyGenerator());
					break;
				}
				case 5://Salsa20
				{
					Key1=std::get<0>(Salsa20KeyGenerator());
					Key2=std::get<1>(Salsa20KeyGenerator());
					break;
				}
				case 6://ChaCha20
				{
					Key1=std::get<0>(ChaCha20KeyGenerator());
					Key2=std::get<1>(ChaCha20KeyGenerator());
					break;
				}
				default:
				{
					Key1="Invalid Option.";
					break;
				}
			}
		}
		else if(typeIndex==3)//非对称
		{
			Key1Prefix="PrivateKey: ";
			Key2Prefix="PublicKey: ";
			switch(algorithmIndex)
			{
				case 1://RSA
				{
					auto tKey=RSAKeyGenerator(4096);
					Key1=std::get<0>(tKey);
					Key2=std::get<1>(tKey);
					break;
				}
				default:
				{
					Key1="Invalid Option.";
					break;
				}
			}
		}

		result=Key1Prefix+Key1+"\n\n\n\n\n\n"+Key2Prefix+Key2;
	}
	else if(methodIndex==1)//处理加密
	{
		if(typeIndex==1)//哈希类
		{
			switch(algorithmIndex)
			{
				case 1://Base64
				{
					Base64Process<ProcessType::Encrypt,SourceType::FromString,DestinationType::ToString> Exec;
					result=Exec(text,"");
					break;
				}
				case 2://SHA3-512
				{
					SHA3_512HashProcess<SourceType::FromString,DestinationType::ToString> Exec;
					result=Exec(text,"");
					break;
				}
				case 3://Whirlpool
				{
					WhirlpoolHashProcess<SourceType::FromString,DestinationType::ToString> Exec;
					result=Exec(text,"");
					break;
				}
				default:
				{
					result="Invalid Option";
					break;
				}
			}
		}
		else if(typeIndex==2)//对称
		{
			switch(algorithmIndex)
			{
				case 1://AES
				{
					AES_CFBProcess<ProcessType::Encrypt,SourceType::FromString,DestinationType::ToString> Exec(keyt1,keyt2);
					std::string bResult=Exec(text,"");
					StringSource(bResult,true,new Base64Encoder(new StringSink(result)));
					break;
				}
				case 2://RC6
				{
					RC6_CFBProcess<ProcessType::Encrypt,SourceType::FromString,DestinationType::ToString> Exec(keyt1,keyt2);
					std::string bResult=Exec(text,"");
					StringSource(bResult,true,new Base64Encoder(new StringSink(result)));
					break;
				}
				case 3://TwoFish
				{
					TwoFish_CFBProcess<ProcessType::Encrypt,SourceType::FromString,DestinationType::ToString> Exec(keyt1,keyt2);
					std::string bResult=Exec(text,"");
					StringSource(bResult,true,new Base64Encoder(new StringSink(result)));
					break;
				}
				case 4://Serpent
				{
					Serpent_CFBProcess<ProcessType::Encrypt,SourceType::FromString,DestinationType::ToString> Exec(keyt1,keyt2);
					std::string bResult=Exec(text,"");
					StringSource(bResult,true,new Base64Encoder(new StringSink(result)));
					break;
				}
				case 5://Salsa20
				{
					Salsa20Process<ProcessType::Encrypt,SourceType::FromString,DestinationType::ToString> Exec(keyt1,keyt2);
					std::string bResult=Exec(text,"");
					StringSource(bResult,true,new Base64Encoder(new StringSink(result)));
					break;
				}
				case 6://ChaCha20
				{
					ChaCha20Process<ProcessType::Encrypt,SourceType::FromString,DestinationType::ToString> Exec(keyt1,keyt2);
					std::string bResult=Exec(text,"");
					StringSource(bResult,true,new Base64Encoder(new StringSink(result)));
					break;
				}
				default:
				{
					result="Invalid Option";
					break;
				}
			}

		}
		else if(typeIndex==3)//非对称
		{
			switch(algorithmIndex)
			{
				case 1://RSA
				{
					RSAPublicProcess<PublicProcessType::Encryption,SourceType::FromString,DestinationType::ToString> Exec(keyt1);
					result=Exec(text,"");
					break;
				}
				default:
				{
					result="Invalid Option";
					break;
				}
			}
		}
	}
	else if(methodIndex==2)//处理解密
	{
		if(typeIndex==1)//哈希类
		{
			switch(algorithmIndex)
			{
				case 1://Base64
				{
					Base64Process<ProcessType::Decrypt,SourceType::FromString,DestinationType::ToString> Exec;
					result=Exec(text,"");
					break;
				}
				case 2://SHA3-512
				{
					result="Error - One-way Function";
					break;
				}
				case 3://Whirlpool
				{
					result="Error - One-way Function";
					break;
				}
				default:
				{
					result="Invalid Option";
					break;
				}
			}
		}
		else if(typeIndex==2)//对称
		{
			switch(algorithmIndex)
			{
				case 1://AES
				{
					AES_CFBProcess<ProcessType::Decrypt,SourceType::FromString,DestinationType::ToString> Exec(keyt1,keyt2);
					std::string bResult;
					StringSource(text,true,new Base64Decoder(new StringSink(bResult)));
					result=Exec(bResult,"");
					break;
				}
				case 2://RC6
				{
					RC6_CFBProcess<ProcessType::Decrypt,SourceType::FromString,DestinationType::ToString> Exec(keyt1,keyt2);
					std::string bResult;
					StringSource(text,true,new Base64Decoder(new StringSink(bResult)));
					result=Exec(bResult,"");
					break;
				}
				case 3://TwoFish
				{
					TwoFish_CFBProcess<ProcessType::Decrypt,SourceType::FromString,DestinationType::ToString> Exec(keyt1,keyt2);
					std::string bResult;
					StringSource(text,true,new Base64Decoder(new StringSink(bResult)));
					result=Exec(bResult,"");
					break;
				}
				case 4://Serpent
				{
					Serpent_CFBProcess<ProcessType::Decrypt,SourceType::FromString,DestinationType::ToString> Exec(keyt1,keyt2);
					std::string bResult;
					StringSource(text,true,new Base64Decoder(new StringSink(bResult)));
					result=Exec(bResult,"");
					break;
				}
				case 5://Salsa20
				{
					Salsa20Process<ProcessType::Decrypt,SourceType::FromString,DestinationType::ToString> Exec(keyt1,keyt2);
					std::string bResult;
					StringSource(text,true,new Base64Decoder(new StringSink(bResult)));
					result=Exec(bResult,"");
					break;
				}
				case 6://ChaCha20
				{
					ChaCha20Process<ProcessType::Decrypt,SourceType::FromString,DestinationType::ToString> Exec(keyt1,keyt2);
					std::string bResult;
					StringSource(text,true,new Base64Decoder(new StringSink(bResult)));
					result=Exec(bResult,"");
					break;
				}
				default:
				{
					result="Invalid Option";
					break;
				}
			}
		}
		else if(typeIndex==3)//非对称
		{
			switch(algorithmIndex)
			{
				case 1://RSA
				{
					RSAPrivateProcess<PrivateProcessType::Decryption,SourceType::FromString,DestinationType::ToString> Exec(keyt1);
					result=Exec(text,"");
					break;
				}
				default:
				{
					result="Invalid Option";
					break;
				}
			}
		}
	}


	return result;
}