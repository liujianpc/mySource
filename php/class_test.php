<?php 
    /**
    * 
    */
    class Girl
    {
        private $age = 50;
        public $name = "fuck";
        private function Age()
        {
            if ($this->age <= 18) {
                    echo "I am a girl";                
            }

            elseif ($this->age < 30) {
                    echo "I am a woman";
            }
            elseif ($this->age <= 60) {
                    echo "I am a old woman";
            }
            else{
                echo "I am a very old woman";
            }
        }
//调用私有方法
        public function getAge(){

            $this->Age();
        }

        public function setAge($age_1){

            $this->age = $age_1;
        }
    }

    $g = new Girl();
    //$g->Age();
    echo $g->name;
    $g->getAge();
    $g->setAge(80);
    $g->getAge();
       
?>