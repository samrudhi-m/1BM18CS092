<template>
  <div class="card-expansion">
    <div class="container">
      <div v-for="(product,index) in products" :key="index">
        <div class="card-button-container">
          <div class="button-box">
            <md-button class="md-accent" v-on:click="deleteProduct(product.id)">Delete</md-button>
            <md-button class="md-primary" :href="'/update/' + product.id">Edit</md-button>
          </div>
          <!-- 
        Book card layout
          -->
          <div v-if="product.book">
            <md-card class="rounded-card">
              <md-ripple>
                <md-card-media>
                  <a :href="'/product/' + product.id">
                    <img
                      v-bind:src="'http://localhost:8080/'+product.book.image"
                      alt="product.title"
                    />
                  </a>
                </md-card-media>

                <md-card-header>
                  <div class="md-title">
                    {{product.title}}
                    <md-chip class="donation-chip md-primary" v-if="product.donation">D</md-chip>
                  </div>
                  <div class="md-subhead">by {{product.book.author}}</div>
                </md-card-header>

                <md-card-expand>
                  <md-card-actions md-alignment="space-between">
                    <div>
                      <md-chip>{{product.sem}}</md-chip>
                      <md-chip>{{product.branch}}</md-chip>
                    </div>
                    <md-card-expand-trigger>
                      <md-button class="md-icon-button">
                        <md-icon>keyboard_arrow_down</md-icon>
                      </md-button>
                    </md-card-expand-trigger>
                  </md-card-actions>

                  <md-card-expand-content>
                    <md-card-content>
                      Published by {{product.book.publisher}}
                      <br />
                      Contact: {{product.book.phone}}
                      <br />
                      Posted at: {{product.createdAt}}
                      <br />
                    </md-card-content>
                  </md-card-expand-content>
                </md-card-expand>
              </md-ripple>
            </md-card>
          </div>

          <!-- 
        Drive card layout
          -->
          <div v-if="product.drive">
            <md-card class="rounded-card">
              <md-ripple>
                <md-card-header>
                  <a :href="'/product/' + product.id">
                    <div class="md-title">{{product.title}}</div>
                    <div class="md-subhead">{{product.drive.description}}</div>
                  </a>
                </md-card-header>

                <md-card-expand>
                  <md-card-actions md-alignment="space-between">
                    <div>
                      <md-chip>{{product.sem}}</md-chip>
                      <md-chip>{{product.branch}}</md-chip>
                    </div>
                    <md-card-expand-trigger>
                      <md-button class="md-icon-button">
                        <md-icon>keyboard_arrow_down</md-icon>
                      </md-button>
                    </md-card-expand-trigger>
                  </md-card-actions>

                  <md-card-expand-content>
                    <md-card-content>
                      Links to: {{product.drive.url}}
                      <br />
                      Posted at: {{product.createdAt}}
                      <br />
                    </md-card-content>
                  </md-card-expand-content>
                </md-card-expand>
              </md-ripple>
            </md-card>
          </div>

          <!-- 
        Other card layout
          -->
          <div v-if="product.other">
            <md-card class="rounded-card">
              <md-ripple>
                <md-card-media>
                  <a :href="'/product/' + product.id">
                    <img
                      v-bind:src="'http://localhost:8080/'+product.other.image"
                      alt="product.title"
                    />
                  </a>
                </md-card-media>

                <md-card-header>
                  <div class="md-title">
                    {{product.title}}
                    <md-chip class="donation-chip md-primary" v-if="product.donation">D</md-chip>
                  </div>

                  <div class="md-subhead">{{product.other.description}}</div>
                </md-card-header>

                <md-card-expand>
                  <md-card-actions md-alignment="space-between">
                    <div>
                      <md-chip>{{product.sem}}</md-chip>
                      <md-chip>{{product.branch}}</md-chip>
                    </div>
                    <md-card-expand-trigger>
                      <md-button class="md-icon-button">
                        <md-icon>keyboard_arrow_down</md-icon>
                      </md-button>
                    </md-card-expand-trigger>
                  </md-card-actions>

                  <md-card-expand-content>
                    <md-card-content>
                      Contact: {{product.other.phone}}
                      <br />
                      Posted at: {{product.createdAt}}
                      <br />
                    </md-card-content>
                  </md-card-expand-content>
                </md-card-expand>
              </md-ripple>
            </md-card>
          </div>
        </div>
      </div>
    </div>
  </div>
</template>

<script>
import axios from "axios";

export default {
  name: "user-products",
  data() {
    return {
      products: {}
    };
  },
  methods: {
    async userProducts() {
      try {
        await axios
          .get(
            "http://localhost:8080/api/users/" +
              this.$store.state.userId +
              "/things"
          )
          .then(response => {
            this.products = response.data;
            console.log(response.data);
          })
          .catch(e => {
            console.log(e);
          });
      } catch (err) {
        console.log(err);
      }
    },
    async deleteProduct(id) {
      await axios
        .delete("http://localhost:8080/api/things/" + id, {
          headers: { Authorization: "Bearer " + this.$store.state.token }
        })
        .then(response => {
          this.userProducts();
          console.log(response.data);
        })
        .catch(e => {
          console.log(e);
        });
    }
  },
  mounted() {
    this.userProducts();
  }
};
</script> 

<style scoped>
.container {
  margin-top: 40px;
}

.button-box {
  display: flex;
  flex-direction: row;
  align-items: center;
  justify-content: space-around;
}

.card-button-container {
  display: block;
  border-radius: 25px;
  box-shadow: 0 7px 45px -10px rgba(68, 138, 255, 0.6);
  background: rgb(255, 255, 255);
  background: linear-gradient(
    180deg,
    rgba(255, 255, 255, 1) 0%,
    rgba(68, 138, 255, 1) 100%
  );
  margin: 10px 5px 10px 5px;
}
/* .card-button-container:hover {
  transform: scale(0.99);
  transition-duration: 0.2s !important;
  box-shadow: 0 7px 45px -10px rgba(150, 170, 180, 0.7) !important;
} */
</style>